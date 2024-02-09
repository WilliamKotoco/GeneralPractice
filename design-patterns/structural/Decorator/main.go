package main

import "fmt"

func main() {
	cafe := NewSimpleCoffee("charles magno")

	fmt.Printf("Coffe to %s with price %f \n", cafe.GetClient(), cafe.GetPrice())

	coffeeMilk := addMilk(cafe)
	fmt.Printf("Coffe to %s with price %f \n ", coffeeMilk.GetClient(), coffeeMilk.GetPrice())

	coffeMilkCapuccino := addCapuccino(coffeeMilk)
	fmt.Printf("Coffe to %s with price %f \n ", coffeMilkCapuccino.GetClient(), coffeMilkCapuccino.GetPrice())

}
