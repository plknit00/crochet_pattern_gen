form.addEventListener("submit", function(event) {
  event.preventDefault();

  const shape = document.getElementById("shape").value;
  const knotType = document.getElementById("stitchType").value; // e.g. "1" or "2"
  const yarnThickness = document.getElementById("yarn").value;

  let data = {
    shape: shape,
    knot_type: knotType,
    yarn_thickness: yarnThickness
  };

  if (shape === "rectangle") {
    data.length = document.getElementById("length").value;
    data.width = document.getElementById("width").value;
  } else if (shape === "circle" || shape === "sphere") {
    data.diameter = document.getElementById("radius").value;
  }

  fetch("http://localhost:5000/generate", {
    method: "POST",
    headers: {"Content-Type": "application/json"},
    body: JSON.stringify(data)
  })
  .then(response => response.json())
  .then(result => {
    if (result.pattern) {
      output.innerHTML = `<pre>${result.pattern}</pre>`;
    } else {
      output.innerHTML = `<p>Error generating pattern.</p>`;
    }
  })
  .catch(error => {
    output.innerHTML = `<p>Error: ${error}</p>`;
  });
});