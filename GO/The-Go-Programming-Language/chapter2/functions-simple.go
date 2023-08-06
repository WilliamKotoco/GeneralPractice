package main

import "fmt"

const freezing, boiling = 32.0, 212.0

func main() {
	fmt.Printf("F: %f \n", freezing)
	fmt.Printf("C: %f", fToC(freezing))

}

/*
(variable type) in the args it's receiving, after that is the type of return
*/
func fToC(freezingF float64) float64 {
	return (freezingF - 32) * 5 / 9
}
