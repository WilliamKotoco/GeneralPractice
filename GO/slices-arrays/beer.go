/// a customer can work only with 5 brands of beer. After the end of the day, choose the beer that sells least to be substituted with one of your choice. The beer sells will be random.

package main

import (
	"fmt"
	"math/rand"
	"strings"
)

const SALES_IN_A_DAY = 1000
const MAX_BRANDS = 5

func main() {
	var beers [MAX_BRANDS]string = [MAX_BRANDS]string{"Budweiser", "Heineken", "Skol", "Brahma", "Blue Moon"}
	var sales [MAX_BRANDS]int = [MAX_BRANDS]int{}
	for i := 0; i < SALES_IN_A_DAY; i++ {
		sales[rand.Intn(MAX_BRANDS)]++
	}

	var op int
	for op != 3 {
		fmt.Print("\n Type [1] to search the sales from a specific brand. \n")
		fmt.Print("Type [2] to replace a brand. \n")
		fmt.Print("Type [3] for exit. \n")
		fmt.Scanf("%d", &op)

		switch op {
		case 1:
			search(beers, sales)
		case 2:
			replace_brand(&beers, &sales) /// passing through pointers because values have to change due the new addition
      fmt.Print(beers)
		default:
			fmt.Print("Exiting")

		}

	}

}

func search(beers [MAX_BRANDS]string, sales [MAX_BRANDS]int) {
	var name string
	fmt.Print("\n Type the brand's name: ")
	fmt.Scanf("%s", &name)
	for i := 0; i < MAX_BRANDS; i++ {
		/// check for matches being case insensitive
		if strings.EqualFold(name, beers[i]) {
			fmt.Printf("The beer %s sold %d today", beers[i], sales[i])
			return
		}
	}
	fmt.Print("The brand " + name + " was not found")

}

func replace_brand(beers *[MAX_BRANDS]string, sales *[MAX_BRANDS]int) {
	var name string
	fmt.Printf("Name of the new beer: ")
	fmt.Scanf("%s", &name)

	var min int = sales[0]
	var pos int = 0
	for i := 1; i < MAX_BRANDS; i++ {
		if sales[i] < min {
			min = sales[i]
			pos = i
		}

	}

	beers[pos] = name
}
