package main

import "fmt"

func main() {

	facade := newFacade()
	fmt.Println("[1] Close shopping cart")
	fmt.Println("[2] Pay")
	fmt.Println("[3] Add item on cart")

	var opcao int
	fmt.Scanf("%d", &opcao)

	switch opcao {
	case 1:
		err := facade.finishOrder()
		if err == nil {
			fmt.Println("Order finished with success")
		}
	case 2:
		err := facade.pay()
		if err == nil {
			fmt.Println("Payment with success")
		}
	case 3:
		err := facade.addItemCart("teste")
		if err == nil {
			fmt.Println("item added")
		}
	}
}
