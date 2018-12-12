defmodule AdventOfCodeHelpers do
  def read(file) do
    File.open!(file, [:read]) |> IO.read(:all) |> String.trim() |> String.split("\n")
  end
end
