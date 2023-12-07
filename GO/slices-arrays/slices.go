package main

import "fmt"

func main() {
	s := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	fmt.Printf("len = %d, cap = %d, %v \n", len(s), cap(s), s)
	fmt.Printf("len = %d, cap = %d, %v \n ", len(s[:0]), cap(s[:0]), s[:0]) /// even if it's empty, it still have the same capacity
	fmt.Printf("len = %d, cap = %d, %v \n", len(s[:5]), cap(s[:5]), s[:5])
	/* by using the s[5:] we choose to discard the first five values of the slice. In this way, it'll reduce the capacity.

	It's the same as it is in C, for example. When you allocate 10 spaces and use only those first 5 spaces, the rest is still avaliable for
	future use. However, if you start your array in the 5th index, the 5 ones before it will be unacessible
	*/
	fmt.Printf("len = %d, cap = %d, %v \n", len(s[5:]), cap(s[5:]), s[5:])

	/*
		The go programming language doubles the capacity (for safety reasons)whenever you need append operations.
		To optimize the space complexity, make sure to always initialize the slices with the amount of space you
		think you'll use for sure.
	*/
	s = append(s, 110)
	fmt.Printf("len = %d, cap = %d, %v", len(s), cap(s), s)
}
