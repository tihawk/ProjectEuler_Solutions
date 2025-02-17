package main

import "fmt"

// We know the number has to be divisible by 5, so it has to end on 5 or 0
// We know the number has to be an even number, to be divisible by 2
// 20 is the first number evenly divisible by 20
// We know the number has to be divisible by 20, so just increase by 20
// Therefore, we need to only check every 20th number, starting from 20
func (s Solution) P5() {
	n := 20;
	score := 0;

	for true {
	  for i := 2; i <= 20; i++ {
	  	if n % i == 0 {
	  		score++;
	  	}
	  }

	  if score == 19 {
	  	break;
	  }
		score = 0;
		n += 20;
	}
	fmt.Println("Smallest positive integer evenly divisible by all numbers from 1 to 20:", n);
}
