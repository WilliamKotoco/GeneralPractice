/// The main goal of this program is to explore the use of structs in go.

/// simulate a converstaion between a human and a alien, with the alien converting their message to the human language and 
/// the human converting to alien one
package main

import "fmt"


type Human struct{
  Name string
  earth_mail Mail
}

type Alien struct{
 Name string
  alien_mail Mail
}

type Mail struct{
  Message string
  From string
  To string
}

type Box struct{
  author_last_message string 
  message Mail
}
/// decode the human language to the alien one. 
func (alien Alien) decode(original string) string{
  var code string = EncryptPlaintext(original, 69)
  return code 
}

/// decode the alien message to the human one 
func (human Human) decode(original string) string{
  var code string = DecryptCiphertext(original, 69)
  return code 
}

/// sends the message and stores it in the box. Box is passed as a pointer 
func (mail Mail) send_message(box *Box){
  fmt.Print("Message is being sent...")
  fmt.Printf("\n %s sent %s to %s", mail.From, mail.Message, mail.To)
  box.author_last_message = mail.From
  box.message= mail
}



func main(){
  var alien Alien
  var human Human
  var box Box
  var message_arrived string
  alien.Name = "Alien"
  alien.alien_mail.To = "Human"
  alien.alien_mail.From = "Alien"
  alien.alien_mail.Message = "Yvccf yldre"
  /// pass the box by reference so the changes keeps outside the send_message function
  alien.alien_mail.send_message(&box)
  message_arrived = human.decode(box.message.Message)

  fmt.Printf("\n Human read %s", message_arrived)
  
  human.Name = "Human"
  human.earth_mail.To = "Alien"
  human.earth_mail.From = "Human"
  human.earth_mail.Message = "Hello Alien"
  human.earth_mail.send_message(&box)

  message_arrived = alien.decode(box.message.Message)
  fmt.Printf(" \n Alien read: %s ", message_arrived)
  

  
}
