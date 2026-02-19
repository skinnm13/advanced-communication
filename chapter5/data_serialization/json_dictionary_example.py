#!/usr/bin/env python3

import json

# Define a Python dictionary.

d = {
    "name": "Terry Todd",
    "age" : 100,
    "employer" : "McMaster University"
}

print('*'*27)
print(type(d))
print(d)

# Serialize it using JSON.
d_json_enc = json.dumps(d)
print('*'*27)
print(type(d_json_enc))
print(d_json_enc)

# Deserialize it using JSON.
d_json_enc_dec = json.loads(d_json_enc)
print('*'*27)
print(type(d_json_enc_dec))
print(d_json_enc_dec)

# dumps(dictionary) == string
# loads(string) == dictionary

