#!/usr/bin/env python3.7
# vi:ai:et sta sw=4 ts=4 sts=4
#
#
import sys
import re

hasu_layout_org = [
	[  -200  , 100, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100, 100, 100, -1050,                                                    ],
	[100,-100, 100, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100,-100],

	[100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,      -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100],
	[  150 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  150 ,      -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100],
	[  175 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  125 ,      -50,     -300     , -50, 100, 100, 100, 100, -50, 100, 100],
	[100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,   200   ,      -50,-100, 100,-100, -50, 100, 100, 100, 100, -50, 100, 100],
	[100, 100, 100, 100, 100,      300     , 100, 100, 100, 100, 100, 100, 100,      -50, 100, 100, 100, -50,   200   , 100, 100, -50, 100, 100],
	]

hasu_layout_oth = [
	[  -200  , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, -1050,                                                    ],
	[100,-100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,-100,      -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100,-100],

	[100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,      -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100],
	[   200  , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,      -50, 100, 100, 100, -50, 100, 100, 100, 100, -50, 100, 100],
	[   200  , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,      -50,     -300     , -50, 100, 100, 100, 100, -50, 100, 100],
	[100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,-100, 100,      -50,-100, 100,-100, -50, 100, 100, 100, 100, -50, 100, 100],
	[100, 100, 100, 100, 100,      300     , 100, 100, 100, 100, 100, 100, 100,      -50, 100, 100, 100, -50,   200   , 100, 100, -50, 100, 100],
	]

hasu_layout = hasu_layout_oth


layers = {
        '_COLEMAKDHM' : 0,
        '_PROGKEYS'   : 1,
        '_UMLAUTE'    : 2,
        '_MOVEMENT'   : 3,
        '_QWERTY'     : 4,
        }

replacements = [
        ('RALT(KC_Q)', 'KC_AE'   , '_UMLAUTE'),
        ('RALT(KC_P)', 'KC_OE'   , '_UMLAUTE'),
        ('RALT(KC_Y)', 'KC_UE'   , '_UMLAUTE'),
        ('RALT(KC_S)', 'KC_SZ'   , '_UMLAUTE'),
        ('DF(4)'     , 'DF_QWRT' , '*'),
        ('DF(0)'     , 'DF_COLM' , '*'),
        ('TT(1)'     , 'TT_PROG' , '*'),
        ('TO(3)'     , 'TO_MOV'  , '*'),
        ('KC_LCTL'   , 'TD_DCTL' , '_COLEMAKDHM'),
        ('KC_LSFT'   , 'KC_UMLT' , '_COLEMAKDHM'),
        ('KC_RCTL'   , 'TD_DALT' , '_COLEMAKDHM'),
        ('KC_HASH'   , 'TD_KHCIR', '_PROGKEYS'),
        ('KC_DLR'    , 'TD_CRNCY', '_PROGKEYS'),
        ('KC_LCBR'   , 'TD_CBRC' , '_PROGKEYS'),
        ('KC_LPRN'   , 'TD_RBRC' , '_PROGKEYS'),
        ('KC_LBRC'   , 'TD_SBRC' , '_PROGKEYS'),
        ('KC_TRNS'   , 'TO_COLM' , '_MOVEMENT'),
        ]

unit = 10

def id2name(i):
    for k in layers:
        if i == layers[k]:
            return k
    assert(False)


with open(sys.argv[1], 'r') as f:
    data = f.read()

for old, new, layer in replacements:
    if '*' == layer:
        data = data.replace(old, new)

matches = re.findall(r'LAYOUT_all\((.*)\),?\n', data)

for old, new, layer in replacements:
    if '*' == layer:
        continue
    i = layers[layer]
    matches[i] = matches[i].replace(old, new)

layout_no = 0
for match in matches:
    keys = list(map(str.strip, match.split(',')))
    sys.stdout.write('  [{}] = LAYOUT_all(\n'.format(id2name(layout_no)))
    layout_no += 1
    for row in hasu_layout:
        sys.stdout.write('  ')
        for weight in row:
            width = abs(weight) * unit // 100;
            if(weight < 0):
                key = " "
                sys.stdout.write('{:^{width}}'.format(key, width=width))
            else:
                align = '<'
                key = keys.pop(0)
                if 'KC_SPC' == key:
                    align = '^'
                if len(keys) > 0:
                    key += ','
                sys.stdout.write('{:{align}{width}}'.format(key, align=align, width=width))
        sys.stdout.write("\n")
    sys.stdout.write("  ),\n")

