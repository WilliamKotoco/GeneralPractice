package main

import (
	"errors"
	"fmt"
)

type Facade struct {
	cart    *Cart
	payment *Payment
	stock   *Stock
}

func newFacade() *Facade {
	return &Facade{
		cart:    &Cart{},
		payment: &Payment{2},
		stock:   &Stock{},
	}
}

func (f *Facade) finishOrder() error {
	price := f.cart.getTotalPrice()
	f.payment.price = price

	fmt.Printf("Total price: %f", price)

	/// removve all items
	err := f.cart.removeItem(0)
	if err != nil {
		return err
	}

	return nil

}

func (f *Facade) pay() error {
	f.payment.getPrice()
	err := f.payment.process()
	if err != nil {
		return err
	}
	return nil
}

func (f *Facade) addItemCart(item string) error {
	id := f.stock.searchProduct(item)
	if id == 0 {
		return errors.New("Product does not exist")
	}

	err := f.cart.addItem(item)
	if err != nil {
		return err
	}

	return nil
}
