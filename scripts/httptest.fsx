#r "System.Net.Http.dll"
open System.Net.Http

let asyncRequest (url: string) =
  async {
    let client = new HttpClient()
    let! response = client.GetAsync(url)
    let! body = response.Content.ReadAsStringAsync()
    return body
  }

let json = "https://httpbin.org/anything/hello" |> asyncRequest |> Async.RunSynchronously
printfn "%s" json