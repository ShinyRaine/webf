use std::ffi::c_void;
use libc::{c_char, c_uint};
use webf_sys::executing_context::ExecutingContextRustMethods;
use webf_sys::{initialize_webf_api, RustValue};
use crate::dom::init_webf_dom;

mod dom;
#[no_mangle]
pub extern "C" fn init_webf_polyfill(handle: RustValue<ExecutingContextRustMethods>) {
  let context = initialize_webf_api(handle);
  init_webf_dom(&context);
}