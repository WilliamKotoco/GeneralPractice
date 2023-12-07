package main

	import (
		"errors"
		"fmt"
	)
	
	func main() {
		
	test, err := division(10.0,0)
	
	if err == nil{
		fmt.Printf("Division: %f", test)
	} else {
		fmt.Printf("error: %v",err)
	}
	
}

func division(a,b float64) (float64, error){
	if b == 0{
		return 0, errors.New("Cannot divide by zero")
	} else {
		return a/b, nil
	}

	}
