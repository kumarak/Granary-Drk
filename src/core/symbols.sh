#!/bin/bash

awk '{if ((($4 == "EXPORT_SYMBOL") || ($4 == "EXPORT_SYMBOL_GPL")) && ($3=="vmlinux")) print $2;}' $1 > $2
