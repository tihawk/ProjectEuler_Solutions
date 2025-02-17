package main

import "fmt"

var (
	num = 600851475143;
)

// This is a somehow magically improved version than checking every odd factor.
// I think it comes from this fact:
// All prime numbers, with the exception of 2 and 5, ends with 1, 3, 7, or 9.
// This makes sense, because all numbers ending on 5 are divisible by 5.
func (s Solution) P3() {
	largestPrime := -1;

	// Check for factors of 2
	remainder := 0;
	for true {
		largestPrime = 2;
		remainder = num % 2;
		if remainder != 0 {
			remainder = 0;
			break;
		}
		num /= 2;
	}

	// Check for factors of 3
	for remainder == 0 {
		largestPrime = 3;
		remainder = num % 3;
		if remainder != 0 {
			remainder = 0;
			break;
		}
		num /= 3;
	}

	// Check for odd factors starting from 5 and incrementing by 6
	// Check every i and i+2
	// Also, the largest prime factor can't be larger than the square root of num
	for candidate := 5; candidate * candidate <= num; candidate += 6 {
		// Check i
		for remainder == 0 {
			largestPrime = candidate;
			remainder = num % candidate;
			if remainder != 0 {
				remainder = 0;
				break;
			}
			num /= candidate;
		}
		// Check i+2
		for remainder == 0 {
			largestPrime = candidate + 2;
			remainder = num % (candidate + 2);
			if remainder != 0 {
				remainder = 0;
				break;
			}
			num /= candidate + 2;
		}
	}

	// If after the checks above, the num is still larger than 4, it's a prime
	if num > 4 {
		largestPrime = num;
	}
	fmt.Println("Largest Prime Factor ", largestPrime);
}
