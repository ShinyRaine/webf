/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */

#ifndef WEBF_CORE_RUST_API_EXECUTING_CONTEXT_H_
#define WEBF_CORE_RUST_API_EXECUTING_CONTEXT_H_

#include "document.h"
#include "window.h"
#include "exception_state.h"

namespace webf {

typedef struct Document Document;
typedef struct ExecutingContext ExecutingContext;
typedef struct Window Window;
typedef struct Event Event;
typedef struct EventPublicMethods EventPublicMethods;

struct WebFCreateEventOptions {
  bool bubbles = false;
  bool cancelable = false;
  bool composed = false;
};

using PublicContextGetDocument = WebFValue<Document, DocumentPublicMethods> (*)(ExecutingContext*);
using PublicContextGetWindow = WebFValue<Window, WindowPublicMethods> (*)(ExecutingContext*);
using PublicContextGetExceptionState = WebFValue<SharedExceptionState, ExceptionStatePublicMethods> (*)();
using PublicContextCreateEvent = WebFValue<Event, EventPublicMethods> (*)(ExecutingContext* context, const char* type, ExceptionState& exception_state);
using PublicContextCreateEventWithOptions = WebFValue<Event, EventPublicMethods> (*)(ExecutingContext* context, const char* type, WebFCreateEventOptions* options, ExceptionState& exception_state);

// Memory aligned and readable from WebF side.
// Only C type member can be included in this class, any C++ type and classes can is not allowed to use here.
struct ExecutingContextWebFMethods {
  static WebFValue<Document, DocumentPublicMethods> document(ExecutingContext* context);
  static WebFValue<Window, WindowPublicMethods> window(ExecutingContext* context);
  static WebFValue<SharedExceptionState, ExceptionStatePublicMethods> CreateExceptionState();
  static WebFValue<Event, EventPublicMethods> CreateEvent(ExecutingContext* context, const char* type, ExceptionState& exception_state);
  static WebFValue<Event, EventPublicMethods> CreateEventWithOptions(ExecutingContext* context, const char* type, WebFCreateEventOptions* options, ExceptionState& exception_state);

  double version{1.0};
  PublicContextGetDocument rust_context_get_document_{document};
  PublicContextGetWindow rust_context_get_window_{window};
  PublicContextGetExceptionState rust_context_get_exception_state_{CreateExceptionState};
  PublicContextCreateEvent rust_context_new_event{CreateEvent};
  PublicContextCreateEventWithOptions rust_context_new_event_with_options{CreateEventWithOptions};
};

}  // namespace webf

#endif  // WEBF_CORE_RUST_API_EXECUTING_CONTEXT_H_
