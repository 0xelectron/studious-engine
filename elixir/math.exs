defmodule Math do
  def sum(a, b) do
    do_sum 2, 3
  end

  defp do_sum(a, b) do
    a + b
  end

  def zero?(0) do
    true
  end

  def zero?(x) when is_integer x do
    false
  end

  def sum_list([head | tail], accumulator) do
    sum_list(tail, head + accumulator)
  end

  def sum_list([], accumulator) do
    accumulator
  end

  def double_each([head | tail]) do
    [head *  2 | double_each(tail)]
  end

  def double_each([]) do
    []
  end

end

IO.puts Math.sum 2, 3
IO.puts Math.zero? 0
IO.puts Math.zero? 23
# IO.puts Math.zero? [2, 3, 4]

list = [2, 3, 4]
IO.inspect list, label: "list: "
IO.puts "Sum: #{Math.sum_list(list, 0)}"
IO.inspect Math.double_each(list), label: "Doubled list: "
