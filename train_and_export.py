# train_and_export.py
import torch
import pickle
import numpy as np
from transformers import BertTokenizer, BertModel
from sklearn.linear_model import LinearRegression

# Data
descriptions = [
    "un immeuble de 5 étages",
    "une villa de 2 étages",
    "un immeuble de 10 étages avec parking",
    "une petite maison plain-pied",
    "un complexe résidentiel de luxe",
    "un immeuble moyen avec ascenseur",
    "une école de 3 étages",
    "un centre commercial moderne",
    "un immeuble avec 3 appartements par étage",
    "un immeuble simple de 4 étages"
]

depenses = [
    500000, 2000, 1200000, 150000, 2000000,
    600000, 800000, 2500000, 900000, 400000
]

# Load BERT
tokenizer = BertTokenizer.from_pretrained("bert-base-uncased")
bert_model = BertModel.from_pretrained("bert-base-uncased")
bert_model.eval()

# Function to encode
def encode_descriptions(texts):
    inputs = tokenizer(texts, return_tensors="pt", padding=True, truncation=True, max_length=64)
    with torch.no_grad():
        outputs = bert_model(**inputs)
    embeddings = outputs.last_hidden_state[:, 0, :]
    return embeddings.numpy()

# Train model
X = encode_descriptions(descriptions)
y = np.array(depenses)
reg_model = LinearRegression()
reg_model.fit(X, y)

# Save model
with open("linear_model.pkl", "wb") as f:
    pickle.dump(reg_model, f)

# Save tokenizer and BERT model
tokenizer.save_pretrained("bert_model/")
bert_model.save_pretrained("bert_model/")
print("Model exported successfully.")
