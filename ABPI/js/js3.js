function myFunction3() {
  document.getElementById("myDropdown3").classList.toggle("show3");
}

// Close the dropdown menu if the user clicks outside of it
$("#close3").on("click",function(){
  if (!event.target.matches('.dropbtn3')) {
    var dropdowns = document.getElementsByClassName("dropdown-content3");
    var i;
    for (i = 0; i < dropdowns.length; i++) {
      var openDropdown = dropdowns[i];
      if (openDropdown.classList.contains('show3')) {
        openDropdown.classList.remove('show3');
      }
    }
  }
});
  

