# --- Part Two ---

defmodule ChronalCalibration2 do
  def solve() do
    f = File.open!("./input.txt", [:read])
    input = IO.read(f, :all) |> String.trim() |> String.split("\n")
    {frequency, _} =
      Enum.reduce_while(Stream.cycle(input), {0, [0]}, fn calibration, {frequency, f_list} ->
        frequency = (String.trim(calibration) |> String.to_integer()) + frequency
        if frequency in f_list do
          {:halt, {frequency, f_list}}
        else
          {:cont, {frequency, f_list ++ [frequency]}}
        end
      end)
    File.close(f)
    frequency
  end
end

IO.puts ChronalCalibration2.solve()

