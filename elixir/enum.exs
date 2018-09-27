list = [2, 3, 4]
IO.inspect list, label: "list"

# function method
IO.puts "Sum: #{Enum.reduce(list, 0, fn(x, acc) -> x + acc end)}"
IO.inspect Enum.map(list, fn(x) -> x * 2 end), label: "Doubled list"

# capture syntax
IO.puts "Sum: #{Enum.reduce(list, 0, &+/2)}"
IO.inspect Enum.map(list, &(&1 * 2)), label: "Doubled list"


list = 1..100
odd? = &(rem(&1, 2) != 0)
IO.inspect Enum.filter(list, odd?), label: "Only odds from 1..100"
IO.inspect list |> Enum.map(&(&1 * 3)) |> Enum.filter(odd?) |> Enum.sum, label: "list from 1..100 mapped by 3, filtered out even, sum"
