#!/usr/bin/env python3

import json

json_str = '{         \
  "red"     : "#f00", \
  "green"   : "#0f0", \
  "blue"    : "#00f", \
  "cyan"    : "#0ff", \
  "magenta" : "#f0f", \
  "yellow"  : "#ff0", \
  "black"   : "#000"  \
}'
print('*'*27)
print('type:', type(json_str))
print('json_str == ', json_str)

print('*'*27)
from_json = json.loads(json_str)
print('type after json.load:', type(from_json))
print('after json.load:', from_json)

print('*'*27)
to_json = json.dumps(from_json)
print(type(to_json))
print(to_json)

#load(string) = dictionary
#dump(dictionary) = string
