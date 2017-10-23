let rec read_lines () =
    try let line = read_line () in
        line :: read_lines()
    with
        End_of_file -> []

let rec compress currentChar times word = ["hello";"hi"]




let () =
    let n = read_lines() in
    let ans = implode (compress ' ' 0 n) in
    print_string ans
