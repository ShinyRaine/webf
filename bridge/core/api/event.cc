/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */

#include "plugin_api/event.h"
#include "plugin_api/event_target.h"
#include "plugin_api/exception_state.h"
#include "plugin_api/executing_context.h"
#include "core/dom/events/event.h"
#include "core/dom/events/event_target.h"

namespace webf {

bool EventPublicMethods::Bubbles(Event* event) {
  return event->bubbles();
}

bool EventPublicMethods::Cancelable(Event* event) {
  return event->cancelable();
}

WebFValue<EventTarget, EventTargetPublicMethods> EventPublicMethods::CurrentTarget(Event* event) {
  EventTarget* current_target = event->currentTarget();
  current_target->KeepAlive();
  return {.value = current_target, .method_pointer = current_target->eventTargetPublicMethods()};
}

bool EventPublicMethods::DefaultPrevented(Event* event) {
  return event->defaultPrevented();
}

WebFValue<EventTarget, EventTargetPublicMethods> EventPublicMethods::SrcElement(Event* event) {
  EventTarget* src_element = event->srcElement();
  src_element->KeepAlive();
  return {.value = src_element, .method_pointer = src_element->eventTargetPublicMethods()};
}

WebFValue<EventTarget, EventTargetPublicMethods> EventPublicMethods::Target(Event* event) {
  EventTarget* target = event->target();
  target->KeepAlive();
  return {.value = target, .method_pointer = target->eventTargetPublicMethods()};
}

bool EventPublicMethods::IsTrusted(Event* event) {
  return event->isTrusted();
}

double EventPublicMethods::TimeStamp(Event* event) {
  return event->timeStamp();
}

const char* EventPublicMethods::Type(Event* event) {
  return event->type().ToStringView().Characters8();
}

void EventPublicMethods::PreventDefault(Event* event, SharedExceptionState* shared_exception_state) {
  event->preventDefault(shared_exception_state->exception_state);
}

void EventPublicMethods::StopImmediatePropagation(Event* event, SharedExceptionState* shared_exception_state) {
  event->stopImmediatePropagation(shared_exception_state->exception_state);
}

void EventPublicMethods::StopPropagation(Event* event, SharedExceptionState* shared_exception_state) {
  event->stopPropagation(shared_exception_state->exception_state);
}

void EventPublicMethods::Release(Event* event) {
  event->ReleaseAlive();
}

WebFValue<Event, EventPublicMethods> ExecutingContextWebFMethods::CreateEvent(ExecutingContext* context, const char* type, ExceptionState& exception_state) {
  AtomicString type_atomic = AtomicString(context->ctx(), type);
  Event* new_event = Event::Create(context, type_atomic, exception_state);
  return {.value = new_event,
    .method_pointer = new_event->eventPublicMethods()};
};

WebFValue<Event, EventPublicMethods> ExecutingContextWebFMethods::CreateEventWithOptions(ExecutingContext* context, const char* type, WebFCreateEventOptions* options, ExceptionState& exception_state) {
  AtomicString type_atomic = AtomicString(context->ctx(), type);
  std::shared_ptr<EventInit> event_init = EventInit::Create();

  event_init->setBubbles(options->bubbles);
  event_init->setCancelable(options->cancelable);
  event_init->setComposed(options->composed);

  Event* new_event = Event::Create(
    context,
    type_atomic,
    event_init,
    exception_state
    );
  return {.value = new_event,
    .method_pointer = new_event->eventPublicMethods()};
};

}  // namespace webf
