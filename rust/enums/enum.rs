// instead of creating a struct and and passing a enum as a member, we can pass the data directly in the enum

// so it is not necessary to have:
    // enum IpAddrKind {
    //     V4,
    //     V6,
    // }

    // struct IpAddr {
    //     kind: IpAddrKind,
    //     address: String,
    // }

// you can put any data into a enum variant
//
enum ipAddr{
    v4(String),
    // or v4(u8,u8,u8,u8)
    v6(String),
}


fn main()
{
    let home = ipAddr::v4(String::from("127.0.0.1"));

    let loopback = ipAddr::v6(String::from("::1"));
}
