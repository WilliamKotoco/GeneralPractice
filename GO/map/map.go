package main

import "fmt"

func main() {

	salaries := map[string]int{"bibi": 9000000}

	fmt.Println(salaries["bibi"])

	/// the make allocate the space for the map, allowing to create an empty one
	salaries2 := make(map[string]int)
	salaries2["cu"] = 10
	fmt.Println(salaries2["cu"])

	salaries["anazerati"] = 200
	salaries["anabibizerati"] = 39

	for nome, salario := range salaries {
		fmt.Printf("%s receives %d ", nome, salario)
	}

}
