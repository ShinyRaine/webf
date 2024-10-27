// Generated by WebF TSDL, don't edit this file directly.
// Generate command: node scripts/generate_binding_code.js
/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */
#ifndef WEBF_CORE_WEBF_API_PLUGIN_API_EVENT_H_
#define WEBF_CORE_WEBF_API_PLUGIN_API_EVENT_H_
#include <stdint.h>
#include "script_value_ref.h"
#include "webf_value.h"
namespace webf {
class EventTarget;
typedef struct EventTargetPublicMethods EventTargetPublicMethods;
class SharedExceptionState;
class ExecutingContext;
class Event;
typedef struct ScriptValueRef ScriptValueRef;
using PublicEventGetBubbles = int32_t (*)(Event*);
using PublicEventGetCancelBubble = int32_t (*)(Event*);
using PublicEventSetCancelBubble = void (*)(Event*, int32_t, SharedExceptionState*);
using PublicEventGetCancelable = int32_t (*)(Event*);
using PublicEventGetCurrentTarget = WebFValue<EventTarget, EventTargetPublicMethods> (*)(Event*);
using PublicEventGetDefaultPrevented = int32_t (*)(Event*);
using PublicEventGetSrcElement = WebFValue<EventTarget, EventTargetPublicMethods> (*)(Event*);
using PublicEventGetTarget = WebFValue<EventTarget, EventTargetPublicMethods> (*)(Event*);
using PublicEventGetIsTrusted = int32_t (*)(Event*);
using PublicEventGetTimeStamp = double (*)(Event*);
using PublicEventGetType = const char* (*)(Event*);
using PublicEventDupType = const char* (*)(Event*);
using PublicEventInitEvent = void (*)(Event*, const char*, int32_t, int32_t, SharedExceptionState*);
using PublicEventPreventDefault = void (*)(Event*, SharedExceptionState*);
using PublicEventStopImmediatePropagation = void (*)(Event*, SharedExceptionState*);
using PublicEventStopPropagation = void (*)(Event*, SharedExceptionState*);
using PublicEventRelease = void (*)(Event*);
struct EventPublicMethods : public WebFPublicMethods {
  static int32_t Bubbles(Event* event);
  static int32_t CancelBubble(Event* event);
  static void SetCancelBubble(Event* event, int32_t cancelBubble, SharedExceptionState* shared_exception_state);
  static int32_t Cancelable(Event* event);
  static WebFValue<EventTarget, EventTargetPublicMethods> CurrentTarget(Event* event);
  static int32_t DefaultPrevented(Event* event);
  static WebFValue<EventTarget, EventTargetPublicMethods> SrcElement(Event* event);
  static WebFValue<EventTarget, EventTargetPublicMethods> Target(Event* event);
  static int32_t IsTrusted(Event* event);
  static double TimeStamp(Event* event);
  static const char* Type(Event* event);
  static const char* DupType(Event* event);
  static void InitEvent(Event* event,
                        const char* type,
                        int32_t bubbles,
                        int32_t cancelable,
                        SharedExceptionState* shared_exception_state);
  static void PreventDefault(Event* event, SharedExceptionState* shared_exception_state);
  static void StopImmediatePropagation(Event* event, SharedExceptionState* shared_exception_state);
  static void StopPropagation(Event* event, SharedExceptionState* shared_exception_state);
  static void Release(Event* event);
  double version{1.0};
  PublicEventGetBubbles event_get_bubbles{Bubbles};
  PublicEventGetCancelBubble event_get_cancel_bubble{CancelBubble};
  PublicEventSetCancelBubble event_set_cancel_bubble{SetCancelBubble};
  PublicEventGetCancelable event_get_cancelable{Cancelable};
  PublicEventGetCurrentTarget event_get_current_target{CurrentTarget};
  PublicEventGetDefaultPrevented event_get_default_prevented{DefaultPrevented};
  PublicEventGetSrcElement event_get_src_element{SrcElement};
  PublicEventGetTarget event_get_target{Target};
  PublicEventGetIsTrusted event_get_is_trusted{IsTrusted};
  PublicEventGetTimeStamp event_get_time_stamp{TimeStamp};
  PublicEventGetType event_get_type{Type};
  PublicEventDupType event_dup_type{DupType};
  PublicEventInitEvent event_init_event{InitEvent};
  PublicEventPreventDefault event_prevent_default{PreventDefault};
  PublicEventStopImmediatePropagation event_stop_immediate_propagation{StopImmediatePropagation};
  PublicEventStopPropagation event_stop_propagation{StopPropagation};
  PublicEventRelease event_release{Release};
};
}  // namespace webf
#endif  // WEBF_CORE_WEBF_API_PLUGIN_API_EVENT_H_