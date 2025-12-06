function searchWord() {
    let word = document.getElementById("wordInput").value;

    fetch(`http://localhost:3000/search?word=${word}`)
    .then(res => res.text())
    .then(data => {
        document.getElementById("result").innerText =
            data === "FOUND" ? "Word FOUND in dictionary" : "Word NOT found";
    });
}
