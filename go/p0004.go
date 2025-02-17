package main

import (
	"fmt"
	"slices"
	"strconv"
	"strings"
)

func (s Solution) P4() {
	largestPalindrome := 101;
	candidate := 0;
	candidateStr := "";
	for i := 100; i < 1000; i++ {
		for j := 1000; j >= 100; j-- {
			if i > j {
				break;
			}
			candidate = i * j;	
			if candidate <= largestPalindrome {
				continue;
			}
			candidateStr = strconv.Itoa(candidate);
			temp := strings.Split(candidateStr, "");
			slices.Reverse(temp);
			reversed := strings.Join(temp, "");
			if candidateStr == reversed {
				largestPalindrome = candidate;
			}
		}
	}

	fmt.Println("Largest palindrome product of 3-digit numbers: ",
	largestPalindrome);

}
