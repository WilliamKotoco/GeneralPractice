package main

type MilkDecorator struct {
	baseCoffee Coffee
}

func (md *MilkDecorator) GetPrice() float64 {
	basePrice := md.baseCoffee.GetPrice()
	return basePrice + 5.50
}

func (md *MilkDecorator) GetClient() string {
	return md.baseCoffee.GetClient()

}

func addMilk(base Coffee) *MilkDecorator {
	return &MilkDecorator{base}
}
