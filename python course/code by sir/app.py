import streamlit as st
import joblib
import numpy as np

# Load model
model = joblib.load("dt_model.joblib")

# Streamlit app
st.title("Binary Classifier")
st.write("Enter values to get a prediction")

# Inputs
feature1 = st.number_input("Feature 1", step=0.01)
feature2 = st.number_input("Feature 2", step=0.01)

# Predict
if st.button("Predict"):
    input_data = np.array([[feature1, feature2]])
    prediction = model.predict(input_data)
    pred_class = "Class 1" if prediction[0] == 1 else "Class 0"
    st.success(f"Predicted Class: {pred_class}")
