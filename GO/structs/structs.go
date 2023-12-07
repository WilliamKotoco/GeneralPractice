package main

import "fmt"

type Person struct{
	Name string
	Age int
	Alive bool
}


func main() {
	bibi := Person{
		Name: "Bibi Rostinho da Silva",
		Age : 14,
		Alive: true,
	}

	fmt.Println(bibi)
	bibi.Age = 18

	fmt.Println(bibi)
}