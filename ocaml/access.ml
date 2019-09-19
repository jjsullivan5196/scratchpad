type 'a contained = {
  name : string;
  value : 'a;
}

type test_city = {
  city : string;
}

let access (c: 'a contained) (func: 'a -> string): string =
  func c.value

let my_city = {
  name = "a city";
  value = {
    city = "los angeles"
  };
}

let get_city_name = access my_city

let city_name = get_city_name (fun con ->
    print_string con.city;
    con.city
  )
