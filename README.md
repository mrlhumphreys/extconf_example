# How to make ruby c extension 

## Create extconf.rb

```ruby
require 'mkmf'

create_header
create_makefile 'name_of_c_file'
```

## create c file

```c
#include "ruby.h"
#include "extconf.h"

// VALUE is ruby type
// define c function
// define init function

void Init_mod_name() {
  VALUE mod = rb_define_module("module_name");
  rb_define_method(mod, "method_name", function, arg_count);
}
```

## Create make file

```bash
ruby extconf.rb
```

## Make object/bundle

```bash
make
```

## Create Ruby File

```ruby
require './module.so/bundle'

include ModuleName
method_name(args)
```
