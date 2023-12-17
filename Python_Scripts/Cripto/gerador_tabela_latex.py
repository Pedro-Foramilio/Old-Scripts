import pandas as pd

def generate_latex_table(table):
    latex_code = "\\begin{table}[h]\n"
    latex_code += "\\centering\n"
    latex_code += "\\begin{tabular}{|" + "|".join(["c"] * len(table.columns)) + "|}\n"
    latex_code += "\\hline\n"

    for _, row in table.iterrows():
        latex_code += " & ".join(map(str, row)) + " \\\\\n"
        latex_code += "\\hline\n"

    latex_code += "\\end{tabular}\n"
    latex_code += "\\caption{Your Table Caption}\n"
    latex_code += "\\label{tab:your_table_label}\n"
    latex_code += "\\end{table}"

    return latex_code

# Example: Reading multiple sheets from an Excel file
excel_file_path = 'analise_linear.xlsx'
sheet_names = [
                'SBOX 1', 'SBOX 2', 'SBOX 3', 'SBOX 4',
                'SBOX 5', 'SBOX 6', 'SBOX 7', 'SBOX8',
                'SBOX9', 'SBOX10', 'SBOX11', 'SBOX12',
                'SBOX13', 'SBOX14', 'SBOX15', 'SBOX16'
              ]  # Add more sheet names as needed

for sheet_name in sheet_names:
    # Read each sheet into a DataFrame
    sheet_data = pd.read_excel(excel_file_path, sheet_name)

    # Generate LaTeX code for the table
    latex_code = generate_latex_table(sheet_data)

    # Print or save the LaTeX code
    print(f"LaTeX code for {sheet_name}:\n")
    print(latex_code)
    print("\n" + "="*30 + "\n")
