defmodule ManagePhotos do
  def clean(dir \\ ".") do
    Enum.each(File.ls!(dir), fn file ->
      fname = "#{dir}/#{file}"
      if File.dir?(fname) do
        clean(fname)
      else
        if String.match?(fname, ~r/\.(json)$/i), do: File.rm!(fname)
      end
    end)
  end

  def move(dir \\ ".", to \\ "/Users/akash/Downloads/Photos/") do
    Enum.each(File.ls!(dir), fn file ->
      fname = "#{dir}/#{file}"
      if File.dir?(fname) do
        move(fname, to)
      else
        new_fname = to <> List.last(String.split(fname, "/"))
        File.rename(fname, new_fname)
      end
    end)
  end
end
