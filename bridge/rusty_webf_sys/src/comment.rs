/*
* Copyright (C) 2022-present The WebF authors. All rights reserved.
*/

use std::ffi::c_double;
use crate::character_data::{CharacterData, CharacterDataRustMethods};
use crate::event_target::{AddEventListenerOptions, EventListenerCallback, EventTarget, EventTargetMethods, RustMethods};
use crate::executing_context::ExecutingContext;
use crate::node::{Node, NodeRustMethods};
use crate::OpaquePtr;

#[repr(C)]
pub struct CommentRustMethods {
  pub version: c_double,
  pub character_data: *const CharacterDataRustMethods,
}

impl RustMethods for CommentRustMethods {}

pub struct Comment {
  pub character_data: CharacterData,
  method_pointer: *const CommentRustMethods,
}

impl Comment {
}

impl EventTargetMethods for Comment {
  /// Initialize the instance from cpp raw pointer.
  fn initialize<T: RustMethods>(ptr: *const OpaquePtr, context: *const ExecutingContext, method_pointer: *const T) -> Self where Self: Sized {
    unsafe {
      Comment {
        character_data: CharacterData::initialize(ptr, context, (method_pointer as *const CommentRustMethods).as_ref().unwrap().character_data),
        method_pointer: method_pointer as *const CommentRustMethods,
      }
    }
  }

  fn ptr(&self) -> *const OpaquePtr {
    self.character_data.ptr()
  }

  fn add_event_listener(&self, event_name: &str, callback: EventListenerCallback, options: &mut AddEventListenerOptions) {
    self.character_data.add_event_listener(event_name, callback, options)
  }
}