# predict_cost.py
import sys
import torch
import pickle
import numpy as np
from transformers import BertTokenizer, BertModel

# Load model
with open("C:/Users/ADAM/Desktop/tache employes/linear_model.pkl", "rb") as f:
    reg_model = pickle.load(f)

tokenizer = BertTokenizer.from_pretrained("bert_model")
bert_model = BertModel.from_pretrained("bert_model")
bert_model.eval()

# Function
def predict(description):
    inputs = tokenizer([description], return_tensors="pt", padding=True, truncation=True, max_length=64)
    with torch.no_grad():
        outputs = bert_model(**inputs)
    embedding = outputs.last_hidden_state[:, 0, :].numpy()
    pred = reg_model.predict(embedding)[0]
    return round(float(pred), 2)

# Command-line interface
if __name__ == "__main__":
    if len(sys.argv) > 1:
        desc = "un immeuble de 3 étages".join(sys.argv[1:])
        print(predict(desc))
    else:
        print("No description given.")

