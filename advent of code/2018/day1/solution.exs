# --- Day 1: Chronal Calibration ---

defmodule ChronalCalibration do
  def solve() do
    f = File.open!("./input.txt", [:read])
    Enum.reduce IO.stream(f, :line), 0, &((String.trim(&1) |> String.to_integer()) + &2)
  end
end

IO.puts ChronalCalibration.solve()
