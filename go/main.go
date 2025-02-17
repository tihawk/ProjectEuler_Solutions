package main

import (
	"os"
	"reflect"
	"strings"
)

type Solution struct {};

func main() {
	num := os.Args[1];
	var s Solution;
	reflect.ValueOf(s).MethodByName(strings.Join([]string{"P", num}, "")).Call([]reflect.Value{});
}
