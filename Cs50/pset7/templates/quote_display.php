<form action = "quote.php">
    <fieldset >
        <div class="form-group">
            A share of <?= htmlspecialchars($name) ?> ( <?= htmlspecialchars($symbol) ?> ) costs  $<?= htmlspecialchars($price) ?>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Back</button>
        </div>
    </fieldset>
</form>
