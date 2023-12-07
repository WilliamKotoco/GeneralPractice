package main

import "fmt"

func main (){
	fmt.Println(sum(30,40,50,30))
	fmt.Println(sum(90,20))
	fmt.Println(sum(2))
}

/// we are passing an undefined number of variables.
func sum(numbers ... int) int{
	var total int

	for _, num := range(numbers){
		total += num
	}

	return total
}