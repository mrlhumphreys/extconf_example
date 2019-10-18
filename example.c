#include "ruby.h"
#include "extconf.h"
#include "functions.h"

static VALUE rb_string(VALUE self, VALUE value) {
  Check_Type(value, T_STRING);

  char* pointer_in = RSTRING_PTR(value);
  char* pointer_out = c_string(pointer_in);
  return rb_str_new2(pointer_out);
}

static VALUE rb_number(VALUE self, VALUE value) {
  Check_Type(value, T_FIXNUM);

  int number_in = NUM2INT(value);
  int number_out = c_number(number_in);
  return INT2NUM(number_out);
}

static VALUE rb_boolean(VALUE self, VALUE value) {
  int boolean_in = RTEST(value);
  int boolean_out = c_boolean(boolean_in);
  if (boolean_out ==1) {
    return Qtrue;
  } else {
    return Qfalse;
  }
}

void Init_example() {
  VALUE ExampleMod = rb_define_module("Example");
  VALUE Helpers = rb_define_class_under(ExampleMod, "Helpers", rb_cObject); 

  rb_define_singleton_method(Helpers, "string", rb_string, 1);
  rb_define_singleton_method(Helpers, "number", rb_number, 1);
  rb_define_singleton_method(Helpers, "boolean", rb_boolean, 1);
}
