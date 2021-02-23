defmodule SHA1.Encoding do
  @on_load  :load_nifs

  def load_nifs do
    :erlang.load_nif("./build/libencoding_nif", 0)
  end

  def hex(_data) do
    raise "NIF hex/1 not implemented"
  end
end

1..5_555_555_555
|> Enum.reduce("clubhouse", fn _i, data ->
  :crypto.hash(:sha, data)
  |> SHA1.Encoding.hex()
end)
|> IO.puts()
