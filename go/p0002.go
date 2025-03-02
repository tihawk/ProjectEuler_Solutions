package main

import "fmt"

const (
	limit = 4000000
)

var result int = 0

func recurse(prev int, curr int) {
	if curr%2 == 0 {
		result += curr
	}
	if curr >= limit {
		fmt.Println("Result ", result)
		return
	}
	recurse(curr, prev+curr)
}

func (s Solution) P2() {
	recurse(1, 2)
}
