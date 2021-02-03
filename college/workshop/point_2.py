from re import findall
from typing import Dict
from getch import getch
from string import punctuation


def process_text(paragraph: str) -> Dict[str, int]:
    text_mapped = {}

    text_mapped["alphabetic"] = len(findall("[a-zA-Z]+?", paragraph))
    text_mapped["digits"] = len(findall("[0-9]+?", paragraph))
    text_mapped["orthographic"] = len(findall(f"[{punctuation}]+?", paragraph))

    return text_mapped


def read_paragraph() -> str:
    paragraph = ""

    print("Enter a paragraph:\n", end="")
    while True:
        paragraph += input() + "\n"
        print("\nPress esc to process this paragraph.", end="", flush=True)
        if ord(getch()) == 27:
            break
        print("\r                                          ", end="", flush=True)
        print("\r", end="", flush=True)
        print("\u001B[1A", end="")

    return paragraph[:101]


def main():
    print("\033\143", end="")
    paragraph = read_paragraph()
    print("\n")
    print(process_text(paragraph))


if __name__ == "__main__":
    main()
