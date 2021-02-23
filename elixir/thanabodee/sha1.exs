1..5_555_555_555
|> Enum.reduce("clubhouse", fn _i, data ->
  :crypto.hash(:sha, data)
  |> Base.encode16(case: :lower)
end)
|> IO.puts()
