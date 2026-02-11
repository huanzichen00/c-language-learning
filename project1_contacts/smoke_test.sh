#!/usr/bin/env bash
set -euo pipefail

SRC="/root/exercise/project1_contacts/contacts_template.c"
BIN="/tmp/contacts_app_test"
DATA="/tmp/contacts_smoke_data.txt"
OUT1="/tmp/contacts_smoke_run1.log"
OUT2="/tmp/contacts_smoke_run2.log"

rm -f "$BIN" "$DATA" "$OUT1" "$OUT2"

gcc -Wall -Wextra -Werror -std=c11 -g "$SRC" -o "$BIN"

# Run 1: add -> list -> find -> update -> delete -> save -> quit
printf "1\nTom 123 tom@x.com\n1\nAmy 456 amy@x.com\n2\n5\nTom\n4\nAmy 999 amy2@x.com\n5\nAmy\n3\nTom\n2\n6\n%s\n0\n" "$DATA" | "$BIN" > "$OUT1"

# Run 2: load -> list -> quit
printf "7\n%s\n2\n0\n" "$DATA" | "$BIN" > "$OUT2"

# Assertions
if ! grep -q "name:Tom" "$OUT1"; then
  echo "FAIL: add/list missing Tom"
  exit 1
fi

if ! grep -q "phone:999" "$OUT1"; then
  echo "FAIL: update not reflected"
  exit 1
fi

if grep -q "name:Tom" "$OUT2"; then
  echo "FAIL: delete/save/load chain incorrect (Tom still exists)"
  exit 1
fi

if ! grep -q "name:Amy" "$OUT2"; then
  echo "FAIL: load/list missing Amy"
  exit 1
fi

echo "PASS: smoke test"
