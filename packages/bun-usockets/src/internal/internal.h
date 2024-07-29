/*
 * Authored by Alex Hultman, 2018-2019.
 * Intellectual property of third-party.

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// clang-format off
#pragma once
#ifndef INTERNAL_H
#define INTERNAL_H

#if defined(_MSC_VER)
#ifndef __cplusplus
#define alignas(x) __declspec(align(x))
#endif

#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#else
#include <stdalign.h>
#endif

#if defined(LIBUS_USE_KQUEUE)
#include <mach/mach.h>
#endif

#if defined(LIBUS_USE_EPOLL) || defined(LIBUS_USE_KQUEUE)
#define LIBUS_MAX_READY_POLLS 1024

void us_internal_loop_update_pending_ready_polls(struct us_loop_t *loop,
                                                 struct us_poll_t *old_poll,
                                                 struct us_poll_t *new_poll,
                                                 int old_events,
                                                 int new_events);
#endif

/* We only have one networking implementation so far */
#include "internal/networking/bsd.h"

/* We have many different eventing implementations */
#if defined(LIBUS_USE_EPOLL) || defined(LIBUS_USE_KQUEUE)
#include "internal/eventing/epoll_kqueue.h"
#endif

#ifdef LIBUS_USE_LIBUV
#include "internal/eventing/libuv.h"
#endif

#ifndef LIKELY
#define LIKELY(cond) __builtin_expect((_Bool)(cond), 1)
#define UNLIKELY(cond) __builtin_expect((_Bool)(cond), 0)
#endif

#ifdef _WIN32
#define IS_EINTR(rc) (rc == SOCKET_ERROR && WSAGetLastError() == WSAEINTR)
#else
#define IS_EINTR(rc) (rc == -1 && errno == EINTR)
#endif

/* Poll type and what it polls for */
enum {
  /* Three first bits */
  POLL_TYPE_SOCKET = 0,
  POLL_TYPE_SOCKET_SHUT_DOWN = 1,
  POLL_TYPE_SEMI_SOCKET = 2,
  POLL_TYPE_CALLBACK = 3,
  POLL_TYPE_UDP = 4,

  /* Two last bits */
  POLL_TYPE_POLLING_OUT = 8,
  POLL_TYPE_POLLING_IN = 16,
};

#define POLL_TYPE_BITSIZE 5 // make sure to update epoll_kqueue.h if you change this
#define POLL_TYPE_KIND_MASK 0b111
#define POLL_TYPE_POLLING_MASK 0b11000
#define POLL_TYPE_MASK (POLL_TYPE_KIND_MASK | POLL_TYPE_POLLING_MASK)

/* Bun APIs implemented in Zig */
void Bun__lock(uint32_t *lock);
void Bun__unlock(uint32_t *lock);

struct addrinfo_request;
struct addrinfo_result_entry {
    struct addrinfo info;
    struct sockaddr_storage _storage;
};
struct addrinfo_result {
    struct addrinfo_result_entry* entries;
    int error;
};

extern int Bun__addrinfo_get(struct us_loop_t* loop, const char* host, struct addrinfo_request** ptr);
extern int Bun__addrinfo_set(struct addrinfo_request* ptr, struct us_connecting_socket_t* socket); 
extern void Bun__addrinfo_freeRequest(struct addrinfo_request* addrinfo_req, int error);
extern struct addrinfo_result *Bun__addrinfo_getRequestResult(struct addrinfo_request* addrinfo_req);


/* Loop related */
void us_internal_dispatch_ready_poll(struct us_poll_t *p, int error,
                                     int events);
void us_internal_timer_sweep(struct us_loop_t *loop);
void us_internal_free_closed_sockets(struct us_loop_t *loop);
void us_internal_loop_link(struct us_loop_t *loop,
                           struct us_socket_context_t *context);
void us_internal_loop_unlink(struct us_loop_t *loop,
                             struct us_socket_context_t *context);
void us_internal_loop_data_init(struct us_loop_t *loop,
                                void (*wakeup_cb)(struct us_loop_t *loop),
                                void (*pre_cb)(struct us_loop_t *loop),
                                void (*post_cb)(struct us_loop_t *loop));
void us_internal_loop_data_free(struct us_loop_t *loop);
void us_internal_loop_pre(struct us_loop_t *loop);
void us_internal_loop_post(struct us_loop_t *loop);

/* Asyncs (old) */
struct us_internal_async *us_internal_create_async(struct us_loop_t *loop,
                                                   int fallthrough,
                                                   unsigned int ext_size);
void us_internal_async_close(struct us_internal_async *a);
void us_internal_async_set(struct us_internal_async *a,
                           void (*cb)(struct us_internal_async *));
void us_internal_async_wakeup(struct us_internal_async *a);

/* Eventing related */
size_t us_internal_accept_poll_event(struct us_poll_t *p);
int us_internal_poll_type(struct us_poll_t *p);
void us_internal_poll_set_type(struct us_poll_t *p, int poll_type);

/* SSL loop data */
void us_internal_init_loop_ssl_data(struct us_loop_t *loop);
void us_internal_free_loop_ssl_data(struct us_loop_t *loop);

/* Socket context related */
void us_internal_socket_context_link_socket(struct us_socket_context_t *context,
                                            struct us_socket_t *s);
void us_internal_socket_context_unlink_socket(
    struct us_socket_context_t *context, struct us_socket_t *s);

void us_internal_socket_after_resolve(struct us_connecting_socket_t *s);
void us_internal_socket_after_open(struct us_socket_t *s, int error);
struct us_internal_ssl_socket_t *
us_internal_ssl_socket_close(struct us_internal_ssl_socket_t *s, int code,
                             void *reason);
                             
int us_internal_handle_dns_results(struct us_loop_t *loop);

/* Sockets are polls */
struct us_socket_t {
  alignas(LIBUS_EXT_ALIGNMENT) struct us_poll_t p; // 4 bytes
  unsigned char timeout;                           // 1 byte
  unsigned char long_timeout;                      // 1 byte
  unsigned short
      low_prio_state; /* 0 = not in low-prio queue, 1 = is in low-prio queue, 2
                         = was in low-prio queue in this iteration */
  struct us_socket_context_t *context;
  struct us_socket_t *prev, *next;
  struct us_socket_t *connect_next;
  struct us_connecting_socket_t *connect_state;
};

struct us_connecting_socket_t {
    alignas(LIBUS_EXT_ALIGNMENT) struct addrinfo_request *addrinfo_req;
    struct us_socket_context_t *context;
    struct us_connecting_socket_t *next;
    struct us_socket_t *connecting_head;
    int options;
    int socket_ext_size;
    unsigned int closed : 1, shutdown : 1, ssl : 1, shutdown_read : 1, pending_resolve_callback : 1;
    unsigned char timeout;
    unsigned char long_timeout;
    uint16_t port;
    int error;
    struct addrinfo *addrinfo_head;
};

struct us_wrapped_socket_context_t {
  struct us_socket_events_t events;
  struct us_socket_events_t old_events;
};

struct us_udp_socket_t {
    alignas(LIBUS_EXT_ALIGNMENT) struct us_poll_t p;
    void (*on_data)(struct us_udp_socket_t *, void *, int);
    void (*on_drain)(struct us_udp_socket_t *);
    void (*on_close)(struct us_udp_socket_t *);
    void *user;
    struct us_loop_t *loop;
    /* An UDP socket can only ever be bound to one single port regardless of how
     * many interfaces it may listen to. Therefore we cache the port after creation
     * and use it to build a proper and full sockaddr_in or sockaddr_in6 for every received packet */
    uint16_t port;
    uint16_t closed : 1;
    uint16_t connected : 1;
    struct us_udp_socket_t *next;
};

#if defined(LIBUS_USE_KQUEUE)
/* Internal callback types are polls just like sockets */
struct us_internal_callback_t {
  alignas(LIBUS_EXT_ALIGNMENT) struct us_poll_t p;
  struct us_loop_t *loop;
  int cb_expects_the_loop;
  int leave_poll_ready;
  void (*cb)(struct us_internal_callback_t *cb);
  mach_port_t port;
  void *machport_buf;
};

#else

struct us_internal_callback_t {
  alignas(LIBUS_EXT_ALIGNMENT) struct us_poll_t p;
  struct us_loop_t *loop;
  int cb_expects_the_loop;
  int leave_poll_ready;
  void (*cb)(struct us_internal_callback_t *cb);
  unsigned has_added_timer_to_event_loop;
};

#endif

#if __cplusplus
extern "C" {
#endif
int us_internal_raw_root_certs(struct us_cert_string_t **out);

#if __cplusplus
}
#endif

/* Listen sockets are sockets */
struct us_listen_socket_t {
  alignas(LIBUS_EXT_ALIGNMENT) struct us_socket_t s;
  unsigned int socket_ext_size;
};

/* Listen sockets are keps in their own list */
void us_internal_socket_context_link_listen_socket(
    struct us_socket_context_t *context, struct us_listen_socket_t *s);
void us_internal_socket_context_unlink_listen_socket(
    struct us_socket_context_t *context, struct us_listen_socket_t *s);

struct us_socket_context_t {
  alignas(LIBUS_EXT_ALIGNMENT) struct us_loop_t *loop;
  uint32_t global_tick;
  unsigned char timestamp;
  unsigned char long_timestamp;
  struct us_socket_t *head_sockets;
  struct us_listen_socket_t *head_listen_sockets;
  struct us_socket_t *iterator;
  struct us_socket_context_t *prev, *next;

  struct us_socket_t *(*on_open)(struct us_socket_t *, int is_client, char *ip,
                                 int ip_length);
  struct us_socket_t *(*on_data)(struct us_socket_t *, char *data, int length);
  struct us_socket_t *(*on_writable)(struct us_socket_t *);
  struct us_socket_t *(*on_close)(struct us_socket_t *, int code, void *reason);
  // void (*on_timeout)(struct us_socket_context *);
  struct us_socket_t *(*on_socket_timeout)(struct us_socket_t *);
  struct us_socket_t *(*on_socket_long_timeout)(struct us_socket_t *);
  struct us_socket_t *(*on_end)(struct us_socket_t *);
  struct us_connecting_socket_t *(*on_connect_error)(struct us_connecting_socket_t *, int code);
  struct us_socket_t *(*on_socket_connect_error)(struct us_socket_t *, int code);
  int (*is_low_prio)(struct us_socket_t *);
  
};

/* Internal SSL interface */
#ifndef LIBUS_NO_SSL

struct us_internal_ssl_socket_context_t;
struct us_internal_ssl_socket_t;
typedef void (*us_internal_on_handshake_t)(
    struct us_internal_ssl_socket_t *, int success,
    struct us_bun_verify_error_t verify_error, void *custom_data);

/* SNI functions */
void us_internal_ssl_socket_context_add_server_name(
    struct us_internal_ssl_socket_context_t *context,
    const char *hostname_pattern, struct us_socket_context_options_t options,
    void *user);
void us_bun_internal_ssl_socket_context_add_server_name(
    struct us_internal_ssl_socket_context_t *context,
    const char *hostname_pattern,
    struct us_bun_socket_context_options_t options, void *user);
void us_internal_ssl_socket_context_remove_server_name(
    struct us_internal_ssl_socket_context_t *context,
    const char *hostname_pattern);
void us_internal_ssl_socket_context_on_server_name(
    struct us_internal_ssl_socket_context_t *context,
    void (*cb)(struct us_internal_ssl_socket_context_t *, const char *));
void *
us_internal_ssl_socket_get_sni_userdata(struct us_internal_ssl_socket_t *s);
void *us_internal_ssl_socket_context_find_server_name_userdata(
    struct us_internal_ssl_socket_context_t *context,
    const char *hostname_pattern);

void *
us_internal_ssl_socket_get_native_handle(struct us_internal_ssl_socket_t *s);
void *us_internal_ssl_socket_context_get_native_handle(
    struct us_internal_ssl_socket_context_t *context);
struct us_bun_verify_error_t
us_internal_verify_error(struct us_internal_ssl_socket_t *s);
struct us_internal_ssl_socket_context_t *us_internal_create_ssl_socket_context(
    struct us_loop_t *loop, int context_ext_size,
    struct us_socket_context_options_t options);
struct us_internal_ssl_socket_context_t *
us_internal_bun_create_ssl_socket_context(
    struct us_loop_t *loop, int context_ext_size,
    struct us_bun_socket_context_options_t options);

void us_internal_ssl_socket_context_free(
    struct us_internal_ssl_socket_context_t *context);
void us_internal_ssl_socket_context_on_open(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_open)(
        struct us_internal_ssl_socket_t *s, int is_client, char *ip,
        int ip_length));

void us_internal_ssl_socket_context_on_close(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_close)(
        struct us_internal_ssl_socket_t *s, int code, void *reason));

void us_internal_ssl_socket_context_on_data(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_data)(
        struct us_internal_ssl_socket_t *s, char *data, int length));

void us_internal_update_handshake(struct us_internal_ssl_socket_t *s);
int us_internal_renegotiate(struct us_internal_ssl_socket_t *s);
void us_internal_trigger_handshake_callback(struct us_internal_ssl_socket_t *s,
                                            int success);
void us_internal_on_ssl_handshake(
    struct us_internal_ssl_socket_context_t *context,
    us_internal_on_handshake_t onhandshake, void *custom_data);

void us_internal_ssl_socket_context_on_writable(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_writable)(
        struct us_internal_ssl_socket_t *s));

void us_internal_ssl_socket_context_on_timeout(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_timeout)(
        struct us_internal_ssl_socket_t *s));

void us_internal_ssl_socket_context_on_long_timeout(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_timeout)(
        struct us_internal_ssl_socket_t *s));

void us_internal_ssl_socket_context_on_end(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_end)(
        struct us_internal_ssl_socket_t *s));

void us_internal_ssl_socket_context_on_connect_error(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_connect_error)(
        struct us_internal_ssl_socket_t *s, int code));

void us_internal_ssl_socket_context_on_socket_connect_error(
        struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *(*on_socket_connect_error)(
        struct us_internal_ssl_socket_t *s, int code));

struct us_listen_socket_t *us_internal_ssl_socket_context_listen(
    struct us_internal_ssl_socket_context_t *context, const char *host,
    int port, int options, int socket_ext_size);

struct us_listen_socket_t *us_internal_ssl_socket_context_listen_unix(
    struct us_internal_ssl_socket_context_t *context, const char *path,
    size_t pathlen, int options, int socket_ext_size);

struct us_connecting_socket_t *us_internal_ssl_socket_context_connect(
    struct us_internal_ssl_socket_context_t *context, const char *host,
    int port, int options, int socket_ext_size, int* is_resolved);

struct us_internal_ssl_socket_t *us_internal_ssl_socket_context_connect_unix(
    struct us_internal_ssl_socket_context_t *context, const char *server_path,
    size_t pathlen, int options, int socket_ext_size);

int us_internal_ssl_socket_write(struct us_internal_ssl_socket_t *s,
                                 const char *data, int length, int msg_more);
int us_internal_ssl_socket_raw_write(struct us_internal_ssl_socket_t *s,
                                     const char *data, int length,
                                     int msg_more);

void us_internal_ssl_socket_timeout(struct us_internal_ssl_socket_t *s,
                                    unsigned int seconds);
void *
us_internal_ssl_socket_context_ext(struct us_internal_ssl_socket_context_t *s);
struct us_internal_ssl_socket_context_t *
us_internal_ssl_socket_get_context(struct us_internal_ssl_socket_t *s);
void *us_internal_ssl_socket_ext(struct us_internal_ssl_socket_t *s);
void *us_internal_connecting_ssl_socket_ext(struct us_connecting_socket_t *c);
int us_internal_ssl_socket_is_shut_down(struct us_internal_ssl_socket_t *s);
void us_internal_ssl_socket_shutdown(struct us_internal_ssl_socket_t *s);

struct us_internal_ssl_socket_t *us_internal_ssl_socket_context_adopt_socket(
    struct us_internal_ssl_socket_context_t *context,
    struct us_internal_ssl_socket_t *s, int ext_size);

struct us_internal_ssl_socket_t *us_internal_ssl_socket_wrap_with_tls(
    struct us_socket_t *s, struct us_bun_socket_context_options_t options,
    struct us_socket_events_t events, int socket_ext_size);
struct us_internal_ssl_socket_context_t *
us_internal_create_child_ssl_socket_context(
    struct us_internal_ssl_socket_context_t *context, int context_ext_size);
struct us_loop_t *us_internal_ssl_socket_context_loop(
    struct us_internal_ssl_socket_context_t *context);
struct us_internal_ssl_socket_t *
us_internal_ssl_socket_open(struct us_internal_ssl_socket_t *s, int is_client,
                            char *ip, int ip_length);

int us_raw_root_certs(struct us_cert_string_t **out);
#endif

#endif // INTERNAL_H
