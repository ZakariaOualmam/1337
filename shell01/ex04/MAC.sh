#!/bin/sh
ifconfig -a | grep -oE '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'
