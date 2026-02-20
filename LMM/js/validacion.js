document.addEventListener("DOMContentLoaded", function () {
    const form = document.getElementById("formContacto");

    form.addEventListener("submit", function (e) {
        let nombre = document.getElementById("nombre").value.trim();
        let email = document.getElementById("email").value.trim();
        let isbn = document.getElementById("isbn").value.trim();

        let errores = [];

        if (nombre === "") {
            errores.push("El nombre es obligatorio");
        }

        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(email)) {
            errores.push("El email no es válido");
        }

        if (isbn.length < 10) {
            errores.push("El ISBN no parece válido");
        }

        if (errores.length > 0) {
            e.preventDefault();
            alert(errores.join("\n"));
        }
    });
});
