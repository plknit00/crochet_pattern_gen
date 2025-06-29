from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route("/generate", methods=["POST"])
def generate():
    data = request.json
    shape = data.get("shape")
    knot_type = str(data.get("knot_type"))

    try:
        if shape == "rectangle":
            length = str(data.get("length"))
            width = str(data.get("width"))
            yarn_thickness = str(data.get("yarn_thickness"))

            output = subprocess.check_output(
                ["./crochet_pattern", shape, length, width, yarn_thickness, knot_type],
                universal_newlines=True
            )

        elif shape == "circle" or shape == "sphere":
            diameter = str(data.get("diameter"))
            yarn_thickness = str(data.get("yarn_thickness"))

            output = subprocess.check_output(
                ["./crochet_pattern", shape, diameter, yarn_thickness, knot_type],
                universal_newlines=True
            )
        else:
            return jsonify({"error": "Invalid shape"})

        return jsonify({"pattern": output})

    except subprocess.CalledProcessError as e:
        return jsonify({"error": str(e)})

if __name__ == "__main__":
    app.run(debug=True)
