from typing import Union

def decimal_to_base_n(num: int, new_base: int, num_base: int=10):
    if num_base != 10:
        num_base_ten_lst = [int(a) for a in str(num)]

        num_base_ten = 0
        for idx, digit in enumerate(reversed(num_base_ten_lst)):
            num_base_ten += digit * (num_base ** idx)
    else:
        num_base_ten = num

    quotient = num_base_ten
    digits_lst = []

    num_iterations = 0
    while quotient > 0:
        quotient, remainder = divmod(quotient, new_base)
        digits_lst.append(str(remainder))
        num_iterations += 1

    return "".join(reversed(digits_lst)), num_iterations

def base16_to_10(num: Union[int, str], reverse: bool=False):
    mapping = {
        "a": 10,
        "b": 11,
        "c": 12,
        "d": 13,
        "e": 14,
        "f": 15,
    }

    if reverse:
        mapping = {v:k for k, v in mapping}
        
        try:
            res = mapping[int(num)]
        except KeyError:
            res = num
    else:
        try:
            res = mapping[num.lower()]
        except KeyError:
            res = num

    return res

def addition(x: Union[int, str], y: Union[int, str], base: int, show_table: bool=False):
    x_digits = [int(base16_to_10(a)) for a in str(x)]
    y_digits = [int(base16_to_10(a)) for a in str(y)]

    xy_lst = sorted([x_digits, y_digits], key=len, reverse=True)
    first = xy_lst[0]
    second = xy_lst[1]
    first.reverse()
    first = first + [0]
    second.reverse()
    second += [0] * (len(first) - len(second))
    carry_lst = []
    carry_over = 0
    res_lst = []
    for x_dig, y_dig in zip(first, second):
        carry_lst.append(carry_over)
        res = x_dig + y_dig + carry_over
        if res >= base:
            res = res - base
            carry_over = 1
        else:
            carry_over = 0
        
        res_lst.append(str(res))

    if res_lst[-1] == "0":
        del res_lst[-1]
        del carry_lst[-1]
        del first[-1]
        del second[-1]

    if show_table:
        carry_lst_tex = "Carry Over &" + "& ".join(reversed([str(x) for x in carry_lst])) + " \\\\"
        skip_line = "\\\\"
        first_lst_tex = "& " + "& ".join(reversed([str(x) for x in first])) + " \\\\"
        second_lst_tex = "+ & " + "& ".join(reversed([str(x) for x in second])) + " \\\\"
        sum_line = "\\hline"
        res_lst_tex = "& " + "& ".join(reversed(res_lst))

        header = "\\begin{tabular}" + "{" + "c"*(len(carry_lst) + 1) + "}"
        footer = "\\end{tabular}"

        for tex_str in [header, carry_lst_tex, skip_line, first_lst_tex, second_lst_tex, 
                        sum_line, res_lst_tex, footer]:
            print(tex_str)

    return "".join(reversed(res_lst))

def decimal_to_complement(num: int):
    unsigned, _ = decimal_to_base_n(num=abs(num), new_base=2)
    padded = unsigned.zfill(8)

    if num >= 0:
        return padded

    digits = [int(x) for x in padded]
    negated = "".join([str(-1 * (x - 1)) for x in digits])

    res = addition(negated, "00000001", base=2, show_table=True)

    return res

def print_iterations(x, new_base):
    quotient = x

    i = 1
    while quotient > 0:
        start = quotient
        quotient, remainder = divmod(quotient, new_base)
        print(f"\\item Iteration {i}: \\( {start:,} / {new_base} = {quotient:,}, \\text\u007bremainder \u007d {remainder:,} \\)")

        i += 1

def main():
    print(decimal_to_base_n(76, 2))

if __name__ == "__main__":
    main()